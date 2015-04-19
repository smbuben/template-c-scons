# This file is NOT licensed the same as the rest of this project.
#
# Here's the license text for this file:
#
# This is free and unencumbered software released into the public domain.
#
# Anyone is free to copy, modify, publish, use, compile, sell, or distribute
# this software, either in source code form or as a compiled binary, for any
# purpose, commercial or non-commercial, and by any means.
#
# In jurisdictions that recognize copyright laws, the author or authors of
# this software dedicate any and all copyright interest in the software to
# the public domain. We make this dedication for the benefit of the public
# at large and to the detriment of our heirs and successors. We intend this
# dedication to be an overt act of relinquishment in perpetuity of all
# present and future rights to this software under copyright law.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# For more information, please refer to <http://unlicense.org/>

import os

Flags = [
    '-Wall',
    '-Wextra',
    '-Werror',
    '-Wpedantic',
    '-std=c11',
    '-x', 'c',
]

def FindIncludeDirs(cwd):
    include_dirs = []
    for root, dirs, _ in os.walk(cwd):
        [dirs.remove(x) for x in dirs if x.startswith('.')]
        [dirs.remove(x) for x in dirs if x in ['build', 'export']]
        [include_dirs.append('-I' + os.path.abspath(os.path.join(root, x)))
            for x in dirs if x in ['inc']]
    return include_dirs

def FlagsForFile(filename, **kwargs):
    ycm_conf_dir = os.path.dirname(os.path.abspath(__file__))
    final_flags = Flags + FindIncludeDirs(ycm_conf_dir)
    return {'flags' : final_flags, 'do_cache' : True}

