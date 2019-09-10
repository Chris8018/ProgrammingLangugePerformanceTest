for i = 1, 100000 do
    for j = 1, 100 do
        local a = 5 * 5
        local b = a + 5
    end

    for j = 1, 100 do
        local a = 5.5 * 5.5
        local b = a + 5.5
    end

    local array = {}
    for j = 1, 100 do array[j] = 0 end
    for j = 1, 100 do array[50] = array[70] end
    for j = 1, 100 do
        local a = "hello"
        local b = a .. "world"
    end
end
