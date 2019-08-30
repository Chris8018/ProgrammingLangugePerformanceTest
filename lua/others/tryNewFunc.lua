Reduce = function (n, list)
    for key, value in pairs(list) do
        n = n + value
    end

    return n
end

arr = {1, 2, 3, 4}

print(Reduce(0, arr))
