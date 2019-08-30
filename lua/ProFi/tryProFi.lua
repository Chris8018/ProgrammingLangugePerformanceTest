ProFi = require'ProFi'

ProFi:start()
dofile("test2.lua")
ProFi:stop()
-- ProFi:checkMemory(1)
ProFi:writeReport( 'MyProfilingReportfoTest2.txt' )