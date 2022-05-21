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

template <typename, typename = void>
constexpr bool is_iterable{};

template <typename T>
constexpr bool is_iterable<
  T,
  std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
  >
> = true;

template<typename T, typename = enable_if_t<is_iterable<T>>>
inline void errf(const char* fmt, const T& v) {
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

struct RearrangeAndIncrement {
  vector <int> change(int X, int Y);
};

vector <int> RearrangeAndIncrement::change(int X, int Y) {
  if (Y % 10 == 0) {
    auto ret = change(X, Y - 1);
    ret.push_back(Y);
    return ret;
  }

  vector<int> ret;
  ret.push_back(X);
  while (X > 1) {
    if (X % 10 != 0) {
      X += 10 - X % 10;
      ret.push_back(X);
    }
    X /= 10;
    ret.push_back(X);
  }

  if (Y < 10) {
    ret.push_back(Y);
  }
  else {
    vector<int> ten, ds;
    ten.push_back(1);
    for (int d = Y; d > 0; d /= 10) {
      ten.push_back(ten.back() * 10);
      ds.push_back(d % 10);
    }
    int dn = (int)ds.size();

    int cur = 9;
    ret.push_back(cur);
    for (int i = 2; i < dn; ++i) {
      // 10*9
      cur += 10;
      ret.push_back(cur);
      // 90*1
      cur += 8 * ten[i - 1]  - 8;
      ret.push_back(cur);
      for (int j = i - 2; j >= 0; --j) {
        // 99*0*9
        cur += 9 - cur % 10;
        ret.push_back(cur);
        // 99*0*
        cur += 9 * ten[j] - 9;
        ret.push_back(cur);
      }
      // 99*9
    }

    // 10*D
    cur += ds.back() + 1;
    ret.push_back(cur);
    // D0*1
    cur -= ten[dn - 1] + ds.back();
    cur += ds.back() * ten[dn - 1] + 1;
    ret.push_back(cur);
    for (int i = dn - 2; i >= 0; --i) {
      if (ds[i] > 0) {
        cur += ds[i] - cur % 10;
        ret.push_back(cur);
      }
      cur += ds[i] * ten[i] - ds[i];
      ret.push_back(cur);
    }
  }

  ret.erase(unique(ALL(ret)), ret.end());
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
        int retrunValueARRAY[] = {10234, 1234, 1247 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RearrangeAndIncrement theObject;
        eq(0, theObject.change(10234, 1247),retrunValue);
    }
    {
        int retrunValueARRAY[] = {10234, 10244, 10248 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RearrangeAndIncrement theObject;
        eq(1, theObject.change(10234, 10248),retrunValue);
    }
    {
        int retrunValueARRAY[] = {999997, 999998, 999999, 1000000, 1000001 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RearrangeAndIncrement theObject;
        eq(2, theObject.change(999997, 1000001),retrunValue);
    }
    {
        int retrunValueARRAY[] = {1000000, 1000 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RearrangeAndIncrement theObject;
        eq(3, theObject.change(1000000, 1000),retrunValue);
    }
    {
        int retrunValueARRAY[] = {1111111, 1111122, 1111221, 1111232 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RearrangeAndIncrement theObject;
        eq(4, theObject.change(1111111, 1111232),retrunValue);
    }
    {
        int retrunValueARRAY[] = {47 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RearrangeAndIncrement theObject;
        eq(5, theObject.change(47, 47),retrunValue);
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
  (void)getchar();

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
