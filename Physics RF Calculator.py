#Made by Muhammad Adil Zafar Khan
import itertools
import math
import turtle
print('Consider the x-y plane.')
turtle.pu()
turtle.setpos(0.00,-200)
turtle.lt(90)
turtle.pd()
turtle.fd(400)
turtle.pu()
turtle.setpos(-200,0.00)
turtle.rt(90)
turtle.pd()
turtle.fd(400)
turtle.setpos(0.00,0.00)
turtle.pencolor("blue")


forces_trc= [int(x) for x in input("Enter the values of all the forces (in newtons) which are in the top right \nquarter of the x-y plane. Give a space after entering each force. Put a zero \nfor none. ").split()]
Q_forces_trc=[int(x) for x in input("Enter the corresponding angles they make with the horizontal in order. \nGive a space after entering each angle. Put a zero for none. ").split()]
for x,y in zip(forces_trc,Q_forces_trc):
    turtle.lt(y)
    turtle.fd(x)
    turtle.setpos(0.00,0.00)
    turtle.lt(-y)
print()    
forces_tlc=[int(x) for x in input ('Enter the values of all the forces (in newtons) which are in the top left \nquarter of the x-y plane. Give a space after entering each force. Put a zero \nfor none. ').split()]
Q_forces_tlc=[int(x) for x in input("Enter the corresponding angles they make with the horizontal in order. \nGive a space after entering each angle. Put a zero for none. ").split()]
turtle.lt(180)
for x,y in zip(forces_tlc,Q_forces_tlc):
    turtle.rt(y)
    turtle.fd(x)
    turtle.setpos(0.00,0.00)
    turtle.rt(-y)
print()    
forces_brc= [int(x) for x in input('Enter the values of all the forces (in newtons) which are in the bottom right \nquarter of the x-y plane. Give a space after entering each force. Put a zero \nfor none. ').split()]
Q_forces_brc=[int(x) for x in input("Enter the corresponding angles they make with the horizontal in order. \nGive a space after entering each angle. Put a zero for none. ").split()]
turtle.rt(180)
for x,y in zip(forces_brc,Q_forces_brc):
    turtle.rt(y)
    turtle.fd(x)
    turtle.setpos(0.00,0.00)
    turtle.rt(-y)
print()
forces_blc=[int(x) for x in input('Enter the values of all the forces (in newtons) which are in the bottom right \nquarter of the x-y plane. Give a space after entering each force. Put a zero \nfor none. ').split()]
Q_forces_blc=[int(x) for x in input("Enter the corresponding angles they make with the horizontal in order. \nGive a space after entering each angle. Put a zero for none. ").split()]
turtle.lt(180)
for x,y in zip(forces_blc,Q_forces_blc):
    turtle.lt(y)
    turtle.fd(x)
    turtle.setpos(0.00,0.00)
    turtle.lt(-y)
    
    
for x in Q_forces_trc:
    trc_cos=math.cos(math.radians(x))
for x in Q_forces_trc:
    trc_sin=math.sin(math.radians(x))
hctrc = [x*y for x,y in zip(itertools.repeat(trc_cos),forces_trc)]
vctrc = [x*y for x,y in zip(itertools.repeat(trc_sin),forces_trc)]

for x in Q_forces_tlc:
    tlc_cos=math.cos(math.radians(x))
for x in Q_forces_tlc:
    tlc_sin=math.sin(math.radians(x))
hctlc = [x*y for x,y in zip(itertools.repeat(tlc_cos),forces_tlc)]
vctlc = [x*y for x,y in zip(itertools.repeat(tlc_sin),forces_tlc)]

for x in Q_forces_brc:
    brc_cos=math.cos(math.radians(x))
for x in Q_forces_brc:
    brc_sin=math.sin(math.radians(x))
hcbrc = [x*y for x,y in zip(itertools.repeat(brc_cos),forces_brc)]
vcbrc = [x*y for x,y in zip(itertools.repeat(brc_sin),forces_brc)]

for x in Q_forces_blc:
    blc_cos=math.cos(math.radians(x))
for x in Q_forces_blc:
    blc_sin=math.sin(math.radians(x))
hcblc = [x*y for x,y in zip(itertools.repeat(blc_cos),forces_blc)]
vcblc = [x*y for x,y in zip(itertools.repeat(blc_sin),forces_blc)]

sumhctrc=sum(hctrc)
sumhcbrc=sum(hcbrc)
rhcright=sumhctrc+sumhcbrc

sumhctlc=sum(hctlc)
sumhcblc=sum(hcblc)
rhcleft=sumhctlc+sumhcblc

if rhcright >= rhcleft:
    rhc=rhcright-rhcleft
else:
    rhc=(-rhcleft+rhcright)

sumvctrc=sum(vctrc)
sumvctlc=sum(vctlc)
rvctop=sumvctrc+sumvctlc

sumvcblc=sum(vcblc)
sumvcbrc=sum(vcbrc)
rvcbottom=sumvcbrc+sumvcblc

if rvctop >= rvcbottom:
    rvc=rvctop-rvcbottom
else:
    rvc=(-rvcbottom+rvctop)

rfmag=math.sqrt(rvc**2+rhc**2)

turtle.pencolor("red")
turtle.setheading(0)
if rvc>0 and rhc>0:
    rfangle= math.degrees(math.atan(rvc/rhc))
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.lt(rfangle)
    turtle.pd()
    turtle.fd(rfmag)
elif rvc>0 and rhc<0:
    rfangle= math.degrees(math.atan(rvc/(-(rhc))))
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.lt(180)
    turtle.rt(rfangle)
    turtle.pd()
    turtle.fd(rfmag)
elif rvc<0 and rhc>0:
    rfangle= math.degrees(math.atan((-(rvc))/rhc))
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.rt(rfangle)
    turtle.pd()
    turtle.fd(rfmag)
elif rhc == 0 and rvc>0:
    rfangle=90
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.lt(90)
    turtle.pd()
    turtle.fd(rfmag)
elif rhc == 0 and rvc<0:
    rfangle=90
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.rt(90)
    turtle.pd()
    turtle.fd(rfmag)
elif rhc>0 and rvc==0:
    rfangle= math.degrees(math.atan(rvc/rhc))
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.fd(rfmag)
elif rhc<0 and rvc==0:
    rfangle= math.degrees(math.atan(rvc/rhc))
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.lt(180)
    turtle.fd(rfmag)
elif rhc==0 and rvc==0:
    rfangle=0
else:
    rfangle= math.degrees(math.atan(rvc/rhc))
    turtle.pu()
    turtle.setpos(0.00,0.00)
    turtle.lt(180)
    turtle.pd()
    turtle.lt(rfangle)
    turtle.fd(rfmag)
print()
print ("The magnitude of the resultant force is %d." %(rfmag+1))
if rfangle==0 or rfangle==90:
    print ("The angle it makes with the horizontal is %d." %rfangle)
else:
    print ("The angle it makes with the horizontal is %d." %(rfangle+1))
input ()

    


