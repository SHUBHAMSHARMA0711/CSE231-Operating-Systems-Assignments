import numpy
import matplotlib.pyplot

matplotlib.pyplot.title("Scheduling Classes vs Time Graph")

matplotlib.pyplot.xlabel("Priorities of Different Scheduling Classes")
matplotlib.pyplot.ylabel("Completion Time (in seconds)")

file = open("C:\\Users\\shubh\\OS Codes\\question_1_2_Times.txt" , "r")
data = []

for line in file.readlines():
    d = line.split(',')

for i in range(0 , 3):
    data.append(float(d[i]))

file.close

ProcessA = []
ProcessB = []
ProcessC = []

ProcessA.append(data[0])
ProcessA.append(0)
ProcessA.append(0)

ProcessB.append(0)
ProcessB.append(data[1])
ProcessB.append(0)

ProcessC.append(0)
ProcessC.append(0)
ProcessC.append(data[2])

A = matplotlib.pyplot.bar(numpy.arange(3)            , ProcessA , 0.15 , color = "RED")
B = matplotlib.pyplot.bar(numpy.arange(3) + 0.15     , ProcessB , 0.15 , color = "BLUE")
C = matplotlib.pyplot.bar(numpy.arange(3) + 0.15 * 2 , ProcessC , 0.15 , color = "GREEN")

matplotlib.pyplot.xticks(numpy.arange(3) + 0.15 , ["0" , "50" , "50"])
matplotlib.pyplot.legend((A , B , C) , ("SCHED_OTHER" , "SCHED_RR" , "SCHED_FIFO"))

matplotlib.pyplot.show()