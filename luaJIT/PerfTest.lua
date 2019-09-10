-- Performance Test on Lua

-- Test 1: Execution time test
function test1()
    local StartTime = os.clock()

    for i = 1, 100000 do
        for j = 1, 100 do
            local a = 5 * 5;
            local b = a + 5;
        end

        for j = 1, 100 do
            local a = 5.5 * 5.5;
            local b = a + 5.5;
        end

        local array = {};
        for j = 1, 100 do
            array[j] = 0;
        end
        for j = 1, 100 do
            array[50] = array[70];
        end
        for j = 1, 100 do
            local a = "hello";
            local b = a .. "world";
        end
    end

    local EndTime = os.clock()

    local ExeTime = EndTime - StartTime

    return ExeTime
end

-- Test 2: Execution time when calling C Function
-- The different between this test 2 and the one in LuaJIT is the way C Func is used
-- In Lua, C Func is used by sharing memory and the C Lib is compile with lua.h, lualib.h,etc
-- In LuaJIT, C Func is used by LuaJIT's FFI and the C Lib is from C# project, basically native C code
-- Have to run Manually since running with iterator cause some weird problem
function test2()
    local StartTime = os.clock()

    -- Loading FFI from LuaJit
    local ffi = require "ffi"

    -- Define C func
    ffi.cdef[[
        void greet();
        int sum_written_in_c(double a, double b, double c);
    ]]

    -- Load dll
    local dll = ffi.load("CLib.dll")

    -- Test if work
    -- dll.greet()

    for i = 1, 100000000 do
        local a = dll.sum_written_in_c(1, 2, 3)
    end
    

    local EndTime = os.clock()

    local ExeTime = EndTime - StartTime

    return ExeTime
end

-- Test 3: Memory test
function test3()
    for i = 1, 2 do
        local ints = {}
        for j = 1, 100000 do
            ints[j] = j
        end

        local floats = {}
        for j = 1, 100000 do
            floats[j] = j
        end

        local strings = {}
        for j = 1, 100000 do
            strings[j] = j
        end
		-- io.read()
    end
end

-- Run test here

-- Run test 3
-- test3()
-- io.read()


IteratorTime = 1

Reduce = function (n, list)
    for key, value in pairs(list) do
        n = n + value
    end
    return n
end

-- Run test 1
TimeList1 = {}

for i = 1, IteratorTime do
    TimeList1[i] = test1()
end

ElapsedTime1 = Reduce(0, TimeList1) / IteratorTime

print("Test 1 elapsed time: " .. ElapsedTime1 .. "s")

-- Run test 2
-- TimeList2 = {}

-- for i = 1, IteratorTime do
    -- TimeList2[i] = test2()
-- end

-- ElapsedTime2 = Reduce(0, TimeList2) / IteratorTime

-- print("Test 2 elapsed time: " .. ElapsedTime2 .. "s")
