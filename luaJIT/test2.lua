-- Loading FFI from LuaJit
local ffi = require "ffi"

-- Define C func
ffi.cdef[[
    void greet();
    int sum_written_in_c(double a, double b, double c);
]]

-- Load dll
local dll = ffi.load("CLib.dll")

for i = 1, 100000000 do
    local a = dll.sum_written_in_c(1, 2, 3)
end
