lighton4=0
pin=2
gpio.mode(pin,gpio.OUTPUT)
tmr.alarm(1,2000,1,function()
    if lighton4==0 then
        lighton4=1
        gpio.write(pin,gpio.HIGH)
    else
        lighton4=0
         gpio.write(pin,gpio.LOW)
    end
end)
