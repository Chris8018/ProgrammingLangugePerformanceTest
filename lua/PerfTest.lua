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

    print("Test 1 eplapsed time: " .. ExeTime)
end

-- Test 2: Execution time when calling C Function
function test2()
    local StartTime = os.clock()

    -- Load clib.dll
    require("clib")

    for i = 1, 100000000 do
        local a = sum_written_in_c(1, 2, 3)
    end

    local EndTime = os.clock()

    local ExeTime = EndTime - StartTime

    print("Test 2 eplapsed time: " .. ExeTime)
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
    end
end

-- Run test here

-- Run test 3
-- test3()

-- Run test 1
test1()

-- Run test 2
test2()
