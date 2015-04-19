# Copyright (c) 2015 Stephen M Buben <smbuben@gmail.com>
# See project LICENSE for details.

from quickscons import quickc
env = Environment()
quickc.Enable(env)
env.AppendUnique(
    CFLAGS=[
        '-std=gnu11'
    ],
    CXXFLAGS=[
        '-std=gnu++11'
    ])
env.QuickBuild('program')

