-- Call CFun

require("clib")

print(isCFun())

print(sum_written_in_c(1, 10, 3))

-- testing normal C-func from C# project
-- local ffi = require "ffi"

-- -- local dll = ffi.load("clib.dll")
-- print("Before ffi.cdef")
-- ffi.cdef[[
--     void greet();
--     int sum_written_in_c(double a, double b, double c);
-- ]]
-- dll.greet()
-- local funcname = "greet"
-- local handler = dll[funcname]
-- handler()
-- print(dll.sum_written_in_c(5, 10, 25))
-- os.exit(0) -- exit C func
