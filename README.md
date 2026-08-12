# C labs

Lab assignments from the C course at BMSTU (IU7).

Topics run from text file and string processing through dynamic memory, matrices and
linked lists to a reimplementation of `snprintf` and calling C shared libraries from
Python. Every lab carries its own sources, build scripts and a `func_tests` directory with
positive and negative cases, so any of them can be built and checked on its own.

`Additional_tasks` holds two pieces written outside the lab sequence, a word counter over
the files of a project and a doubly linked list.

## Build and test

```bash
cd C_Labs/lab_06_01_01
./build_release.sh
./func_tests/scripts/func_tests.sh
```
