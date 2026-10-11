#!/usr/bin/env python3
"""Scrape the PTA problem set's programming problems into problems.md.

Endpoints discovered from the exam-app JS bundle (static.pintia.cn/exam-app):
  GET /api/problem-sets/{setId}/problem-summaries                 -> counts per type
  GET /api/problem-sets/{setId}/exam-problem-types?examId={setId} -> [{id,title,type,score}, ...]
  GET /api/problem-sets/{setId}/exam-problems/{psPid}             -> {problemSetProblem:{content,...}}

Auth: logged-in cookie in ./.pta_cookie (or env PTA_COOKIE).
Run:  python3 scrape_pta.py [PROGRAMMING]
"""

import json
import os
import sys
import time
import urllib.error
import urllib.request
from datetime import datetime, timezone

HERE = os.path.dirname(os.path.abspath(__file__))
RAW = os.path.join(HERE, "raw")
BASE = "https://pintia.cn"
SET_ID = os.environ.get("PTA_SET", "2101904400470790144")
WANT_TYPE = sys.argv[1] if len(sys.argv) > 1 else "PROGRAMMING"

HEADERS = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) Chrome/130.0 Safari/537.36",
    "Accept": "application/json, text/plain, */*",
    "userAgent": "WEB",  # PTA returns 406 for some endpoints without this
    "referer": f"{BASE}/problem-sets/{SET_ID}/exam/problems/type/7",
    "Cookie": open(os.path.join(HERE, ".pta_cookie"), encoding="utf-8").read().strip()
    if os.path.exists(os.path.join(HERE, ".pta_cookie"))
    else os.environ.get("PTA_COOKIE", ""),
}

PROBLEM_URL = (
    f"{BASE}/problem-sets/{SET_ID}/exam/problems/type/7?problemSetProblemId={{pid}}"
)


def get(path):
    req = urllib.request.Request(BASE + path, headers=HEADERS)
    try:
        with urllib.request.urlopen(req, timeout=30) as r:
            return json.loads(r.read().decode("utf-8"))
    except urllib.error.HTTPError as e:
        sys.exit(f"HTTP {e.code} on {path}\n{e.read().decode('utf-8','replace')[:300]}")
    except json.JSONDecodeError:
        sys.exit(f"not JSON on {path} (cookie expired -> SPA html?)")


def main():
    if not HEADERS["Cookie"]:
        sys.exit("no cookie: write sspu-PTA/.pta_cookie or set PTA_COOKIE")
    os.makedirs(RAW, exist_ok=True)

    meta = get(f"/api/problem-sets/{SET_ID}/exams")
    set_name = meta["problemSet"]["name"]
    summaries = get(f"/api/problem-sets/{SET_ID}/problem-summaries")["summaries"]
    print(f"problem set : {set_name}")
    print(f"summaries   : " + ", ".join(
        f"{k}={v['total']}题/{v['totalScore']}分" for k, v in summaries.items()))

    types = get(f"/api/problem-sets/{SET_ID}/exam-problem-types?examId={SET_ID}")["labels"]
    targets = [t for t in types if t["type"] == WANT_TYPE]
    targets.sort(key=lambda t: t["problemPoolIndex"])
    print(f"{WANT_TYPE}: {len(targets)} problems -> "
          + ", ".join(t["title"] for t in targets[:3]) + " ...")

    items = []
    for i, t in enumerate(targets, 1):
        d = get(f"/api/problem-sets/{SET_ID}/exam-problems/{t['id']}")["problemSetProblem"]
        with open(os.path.join(RAW, f"{t['id']}.json"), "w", encoding="utf-8") as f:
            json.dump(d, f, ensure_ascii=False, indent=1)
        cfg = (d.get("problemConfig") or {}).get("programmingProblemConfig") or {}
        items.append({
            "no": i,
            "pid": t["id"],
            "problemId": d.get("problemId", ""),
            "title": d["title"],
            "score": d.get("score"),
            "author": d.get("author", ""),
            "timeLimit": cfg.get("timeLimit"),
            "memoryLimit": cfg.get("memoryLimit"),
            "codeSizeLimit": cfg.get("codeSizeLimit"),
            "content": (d.get("content") or d.get("description") or "").strip(),
        })
        print(f"  [{i:2d}/{len(targets)}] {t['id']}  {d['title']}")
        time.sleep(0.35)  # be polite

    write_md(items, set_name)


def write_md(items, set_name):
    name = "problems.md" if WANT_TYPE == "PROGRAMMING" else f"problems-{WANT_TYPE.lower()}.md"
    out = os.path.join(HERE, name)
    lines = [
        f"# {set_name} · 编程题（{len(items)} 题）",
        "",
        f"- 题目集: <{BASE}/problem-sets/{SET_ID}/exam/problems/type/7>",
        f"- 抓取时间: {datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M UTC')}",
        f"- 题型: `{WANT_TYPE}`（分值合计 "
        f"{sum(x['score'] or 0 for x in items):g} 分）",
        "",
        "| # | 题目 | 分值 | 时间 | 内存 | 链接 |",
        "|---:|---|---:|---:|---:|---|",
    ]
    for x in items:
        lines.append(
            f"| {x['no']} | {x['title']} | {x['score']:g} | {x['timeLimit']} ms | "
            f"{x['memoryLimit']} KB | [7-{x['no']}](<{PROBLEM_URL.format(pid=x['pid'])}>) |")
    lines.append("\n---\n")
    for x in items:
        lines += [
            f"## {x['no']}. {x['title']}",
            "",
            f"- 题号: `7-{x['no']}` 　分值: **{x['score']:g}** 　作者: {x['author']}",
            f"- 时间限制: {x['timeLimit']} ms 　内存限制: {x['memoryLimit']} KB 　"
            f"代码长度限制: {x['codeSizeLimit']} KB",
            f"- 链接: <{PROBLEM_URL.format(pid=x['pid'])}>",
            "",
            x["content"],
            "",
            "---",
            "",
        ]
    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"wrote {out} ({os.path.getsize(out)} bytes, {len(items)} problems)")


if __name__ == "__main__":
    main()
