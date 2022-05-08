#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
// BEGIN CUT HERE
#define __WATASHI__
// <errf>
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  for (const auto& i: v) {
    errf(fmt, i);
  }
  errf("}\n");
}
// </errf>
// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct Stringversions {
  static const int CHARSET = 26;
  string create(int L, int N);
};

string Stringversions::create(int L, int N) {
  auto dp = vector<vector<int>>(L + 1, vector<int>(CHARSET, 0));
  for (int i = 2; i <= L; ++i) {
    for (int j = 1; j < CHARSET; ++j) {
      for (int k = 0; k <= i; ++k) {
        dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + k * (i - k));
      }
    }
  }
  if (N > dp[L][CHARSET - 1]) {
    return "";
  }

  string ret(L, 'a');
  char* s = &ret[0];
  for (int c = CHARSET - 1; c > 1; --c) {
    errf("%d %d %d %d\n", L, c, N, dp[L][c]);
    for (int j = 0; j <= L; ++j) {
      int NN = N - j * (L - j);
      if (0 <= NN && NN <= dp[L - j][c - 1]) {
        fill(s, s + j, 'a' + c);
        s += j;
        L -= j;
        N = NN;
        break;
      }
    }
  }

  errf("%d %d\n", L, N);
  int t = 0;
  while (t * (L - t) < N) {
    ++t;
  }
  fill(s, s + t, 'b');
  swap(s[t - 1], s[t - 1 + t * (L - t) - N]);

  return ret;
}

// BEGIN CUT HERE
// <main>
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        Stringversions theObject;
        eq(0, theObject.create(5, 1),"hello");
    }
    {
        Stringversions theObject;
        eq(1, theObject.create(7, 0),"xxxxxxx");
    }
    {
        Stringversions theObject;
        eq(2, theObject.create(7, 21),"sponged");
    }
    {
        Stringversions theObject;
        eq(3, theObject.create(27, 351),"");
    }
    {
        Stringversions theObject;
        eq(4, theObject.create(25, 152),"topcoderroundonesubroundb");
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz
 * make_pair first second
 * iterator const_iterator
 * priority_queue
 * push_back
 */
/*
 * vim: ft=cpp.doxygen
 */
// </main>
// END CUT HERE
