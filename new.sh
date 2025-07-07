if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Usage: ./newtask.sh <contest_number> <problem_char>"
  echo "Example: ./newtask.sh 1234 A"
  exit 1
fi

CONTEST=$1
PROBLEM=$2
TASK_NAME="${CONTEST}${PROBLEM}"
TASK_DIR="cf/$TASK_NAME"

if [ -d "$TASK_DIR" ]; then
  echo "Task directory $TASK_DIR already exists."
  exit 1
fi

mkdir -p "$TASK_DIR"

cat > "$TASK_DIR/main.cpp" <<EOL
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
EOL

cat > "$TASK_DIR/readme.md" <<EOL
# Решение на задачу https://codeforces.com/contest/$CONTEST/problem/$PROBLEM
EOL

git add "$TASK_DIR"

echo "Created task $TASK_NAME in $TASK_DIR and added to git."

code -g "$TASK_DIR/main.cpp:11:5"
