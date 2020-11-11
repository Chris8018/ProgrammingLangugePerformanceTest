function test1()
    for i = 1, 100000 do
        for j = 1, 100 do
            a = 5 * 5
            b = a + 5
        end

        for j = 1, 100 do
            a = 5.5 * 5.5
            b = a + 5.5
        end

        array = {}
        for j = 1, 100 do array[j] = 0 end
        for j = 1, 100 do array[50] = array[70] end
        for j = 1, 100 do
            a = "hello"
            b = a .. "world"
        end
    end
end

test1()

-- io.read()
