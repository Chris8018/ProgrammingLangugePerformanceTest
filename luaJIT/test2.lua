function test2()
    -- Loading FFI from LuaJit
    ffi = require "ffi"

    -- Define C func
    ffi.cdef[[
        void greet();
        int sum_written_in_c(double a, double b, double c);
    ]]

    -- Load dll
    dll = ffi.load("CLib.dll")

    for i = 1, 100000000 do
        a = dll.sum_written_in_c(1, 2, 3)
    end
end

test2()

-- io.read()
