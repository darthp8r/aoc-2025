#   Advent of Code 2025, python edition


##  Mamba is RSpec for Python

_I'm still smitten with the rspec test regime_

```
% python -m venv .venv
% pip install --upgrade pip
% pip install -e .
%
% PYTHONPATH=. mamba spec
```



##  Building the wheel

_How are wheels built nowadays?_

Seems as if every three or four of five years there's a new way to build
python packages. TBH I'm a little surprised they're still called _wheels_.

We'll follow today's (Python Packaging User Guide)[https://packaging.python.org/]
of using only the [`pyproject.toml`] file for package description and
[`hatchling`](https://pypi.org/project/hatchling) for the build backend.

>   Note: _backend_ is what builds the wheel, _frontend_ is what installs it

OK, forget `hatchling` because it _requires_ your virtual environment
[to be named .venv](https://github.com/pypa/hatch/pull/1413)
in order to avoid
[a path error](https://github.com/pypa/packaging-problems/issues/751)
when building the wheel:

```
(virtual) [payter@carson ~/Projects/aoc-2025/python]$ python3 -m build
* Creating isolated environment: venv+pip...
* Installing packages in isolated environment:
  - hatchling >= 1.26
* Getting build dependencies for sdist...
* Building sdist...

Traceback (most recent call last):
  File "/usr/home/payter/Projects/aoc-2025/python/virtual/lib/python3.11/site-packages/build/__main__.py", line 179, in _handle_build_error
    yield
  File "/usr/home/payter/Projects/aoc-2025/python/virtual/lib/python3.11/site-packages/build/__main__.py", line 460, in main
    built = build_call(
            ^^^^^^^^^^^
  File "/usr/home/payter/Projects/aoc-2025/python/virtual/lib/python3.11/site-packages/build/__main__.py", line 277, in build_package_via_sdist
    t.extractall(sdist_out)
  File "/usr/local/lib/python3.11/tarfile.py", line 2303, in extractall
    tarinfo, unfiltered = self._get_extract_tarinfo(
                          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/usr/local/lib/python3.11/tarfile.py", line 2392, in _get_extract_tarinfo
    self._handle_fatal_error(e)
  File "/usr/local/lib/python3.11/tarfile.py", line 2390, in _get_extract_tarinfo
    filtered = filter_function(unfiltered, path)
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/usr/local/lib/python3.11/tarfile.py", line 844, in data_filter
    new_attrs = _get_filtered_attrs(member, dest_path, True)
                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/usr/local/lib/python3.11/tarfile.py", line 817, in _get_filtered_attrs
    raise AbsoluteLinkError(member)
tarfile.AbsoluteLinkError: 'aoc2025-1.0/virtual/bin/python3' is a link to an absolute path

ERROR 'aoc2025-1.0/virtual/bin/python3' is a link to an absolute path
```

So let's choose the next backend in the recommendation: good ole `setuptools`

Oh, but never mind, I just can't use my own virtual environment. Fine?
We'll see how this plays out in the workflow.

