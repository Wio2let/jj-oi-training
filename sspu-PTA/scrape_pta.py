#!/usr/bin/env python3
"""Step 1: probe the PTA (pintia.cn) problem-set API with a logged-in cookie.

Usage:
    python3 scrape_pta.py            # probe list endpoints, save raw JSON to raw/
    python3 scrape_pta.py <pid> ...  # probe detail endpoints for given problem ids

Cookie source (first match wins):
    1. environment variable PTA_COOKIE
    2. file ./.pta_cookie  (one line, the whole Cookie: header)
"""

import json
import os
import sys
import urllib.error
import urllib.request

HERE = os.path.dirname(os.path.abspath(__file__))
RAW = os.path.join(HERE, "raw")
BASE = "https://pintia.cn"
SET_ID = os.environ.get("PTA_SET", "2101904400470790144")

HEADERS = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
                  "(KHTML, like Gecko) Chrome/130.0 Safari/537.36",
    "Accept": "application/json, text/plain, */*",
    "referer": f"{BASE}/problem-sets/{SET_ID}/exam/problems/type/7",
    # PTA's frontend sends this marker; some endpoints 406 without it
    "userAgent": "WEB",
}


def load_cookie() -> str:
    c = os.environ.get("PTA_COOKIE", "").strip()
    if c:
        return c
    path = os.path.join(HERE, ".pta_cookie")
    if os.path.exists(path):
        with open(path, encoding="utf-8") as f:
            return f.read().strip()
    sys.exit("No cookie found: set PTA_COOKIE or write sspu-PTA/.pta_cookie")


def get(path: str, fname: str):
    url = BASE + path
    hdrs = dict(HEADERS, Cookie=COOKIE)
    req = urllib.request.Request(url, headers=hdrs)
    try:
        with urllib.request.urlopen(req, timeout=30) as r:
            status, body = r.status, r.read().decode("utf-8", "replace")
    except urllib.error.HTTPError as e:
        status, body = e.code, e.read().decode("utf-8", "replace")
    except Exception as e:                      # network / timeout
        print(f"ERR  {url}\n     {e}")
        return None
    print(f"{status}  {path}")
    out = os.path.join(RAW, fname)
    with open(out, "w", encoding="utf-8") as f:
        f.write(body)
    if status == 200:
        try:
            data = json.loads(body)
            print(f"     saved -> raw/{fname}  (json, {len(body)} bytes)")
            return data
        except json.JSONDecodeError:
            print(f"     saved -> raw/{fname}  (NOT json, probably the SPA html)")
    else:
        print(f"     {body[:200]}")
    return None


def main():
    global COOKIE
    COOKIE = load_cookie()
    os.makedirs(RAW, exist_ok=True)
    args = sys.argv[1:]

    if not args:
        print("== probing list endpoints ==")
        cands = [
            (f"/api/problem-sets/{SET_ID}/exam/problems?type=7&page=0&pageSize=50", "list-exam.json"),
            (f"/api/problem-sets/{SET_ID}/problems?type=7&page=0&pageSize=50", "list-problems.json"),
            (f"/api/problem-sets/{SET_ID}/problems", "list-bare.json"),
            (f"/api/problem-sets/{SET_ID}", "set-meta.json"),
        ]
        for path, fname in cands:
            data = get(path, fname)
            if isinstance(data, list) or isinstance(data, dict):
                dump_ids(data)
        return

    print("== probing detail endpoints ==")
    for pid in args:
        for path, fname in [
            (f"/api/problem-sets/{SET_ID}/problems/{pid}", f"detail-{pid}.json"),
            (f"/api/problem-sets/{SET_ID}/exam/problems/{pid}", f"exam-detail-{pid}.json"),
            (f"/api/problems/{pid}", f"problem-{pid}.json"),
        ]:
            get(path, fname)


def dump_ids(data, depth=0):
    """Print id/title pairs wherever they appear in the JSON blob."""
    if depth > 3:
        return
    if isinstance(data, list):
        for item in data:
            dump_ids(item, depth + 1)
    elif isinstance(data, dict):
        if "id" in data and ("title" in data or "name" in data):
            print(f"     id={data['id']} title={data.get('title') or data.get('name')}")
            return
        for v in data.values():
            if isinstance(v, (list, dict)):
                dump_ids(v, depth + 1)


if __name__ == "__main__":
    main()
