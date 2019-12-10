


co =  coroutine.create ( function ()
       print("oi")
      end)


coroutine.resume(co)



co = coroutine.create(function()
  for i = 1, 10 do
    print(i)
    local x,y =  coroutine.yield()
    print(x , " - " , y)
  end
end)

coroutine.resume(co)

coroutine.resume(co,5,7)
