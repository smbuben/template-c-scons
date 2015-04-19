template-c-scons
================

Personal SCons-built C/C++ template project.

Notes
-----

* Uses https://github.com/smbuben/quickscons.git as a submodule. Remember to
clone with --recursive or initialize manually.

Bugs
----

* There is currently a race condition in the Google Test SConscript. If the
archive has not yet been downloaded/unpacked and a parallel build is run (e.g.
scons -j 2) then unit tests could be compiled before the necessary headers are
available. Either run the build again or pre-build Google Test:

    $ scons gtest

License
-------

The template is licensed under The MIT License.

