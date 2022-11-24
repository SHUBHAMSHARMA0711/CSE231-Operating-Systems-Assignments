import numpy
import matplotlib.pyplot

matplotlib.pyplot.title("Priorities vs Time Graph")

matplotlib.pyplot.xlabel("Priorities of Different Scheduling Classes")
matplotlib.pyplot.ylabel("Completion Time (in seconds)")

ProcessA = []
ProcessB = []
ProcessC = []

file = open("C:\\Users\\shubh\\OS Codes\\question_1_1_Times.txt" , "r")
data = []

for line in file.readlines():
    d = line.split(',')

for i in range(0 , 30):
    data.append(float(d[i]))

file.close

ProcessA.append(data[0])
ProcessA.append(data[3])
ProcessA.append(data[6])
ProcessA.append(data[9])
ProcessA.append(data[12])
ProcessA.append(data[15])
ProcessA.append(data[18])
ProcessA.append(data[21])
ProcessA.append(data[24])
ProcessA.append(data[27])

ProcessB.append(data[1])
ProcessB.append(data[4])
ProcessB.append(data[7])
ProcessB.append(data[10])
ProcessB.append(data[13])
ProcessB.append(data[16])
ProcessB.append(data[19])
ProcessB.append(data[22])
ProcessB.append(data[25])
ProcessB.append(data[28])

ProcessC.append(data[2])
ProcessC.append(data[5])
ProcessC.append(data[8])
ProcessC.append(data[11])
ProcessC.append(data[14])
ProcessC.append(data[17])
ProcessC.append(data[20])
ProcessC.append(data[23])
ProcessC.append(data[26])
ProcessC.append(data[29])

A = matplotlib.pyplot.bar(numpy.arange(10)            , ProcessA , 0.15 , color = "RED")
B = matplotlib.pyplot.bar(numpy.arange(10) + 0.15     , ProcessB , 0.15 , color = "BLUE")
C = matplotlib.pyplot.bar(numpy.arange(10) + 0.15 * 2 , ProcessC , 0.15 , color = "GREEN")

matplotlib.pyplot.xticks(numpy.arange(10) + 0.15 , ["0 9 9" , "0 19 19" , "0 29 29" , "0 39 39" , "0 49 49" , "0 59 59" , "0 69 69" , "0 79 79" , "0 89 89" , "0 99 99"])
matplotlib.pyplot.legend((A , B , C) , ("SCHED_OTHER" , "SCHED_RR" , "SCHED_FIFO"))

matplotlib.pyplot.show()