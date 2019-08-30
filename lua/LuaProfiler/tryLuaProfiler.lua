-- require("test3")
Profi = require("profiler")

Profi:start("testReport")
dofile("test1.lua")
Profi:stop()