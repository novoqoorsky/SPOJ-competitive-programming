"""
http://pl.spoj.com/problems/MWP4_3B/
Dominik Nowogórski
09-11-2017
"""


def to_seconds(hour):
    """ takes an hour in HH:MM:SS format as parameter
        and counts how many seconds it is """
    hh = (ord(hour[0]) - 48) * 10 + ord(hour[1]) - 48
    mm = (ord(hour[3]) - 48) * 10 + ord(hour[4]) - 48
    ss = (ord(hour[6]) - 48) * 10 + ord(hour[7]) - 48
    return 3600 * hh + 60 * mm + ss


def print_result(hour):
    """ takes an hour represented as number of seconds,
        counts it back to HH:MM:SS format and prints it """
    if hour > 0:
        hh = int(hour / 3600)
        mm = int(hour / 60 - hh * 60)
        ss = hour % 60
        print("%02d:%02d:%02d" % (hh, mm, ss))
    else:
        print("0")


t = int(input())    # number of test cases
i = 0
while i < t:
    n = int(input())    # number of submissions
    timeToFall = to_seconds(input())
    longestAsleep = 0
    lastAwake = 9 * 3600    # initialized with seconds representation of 09:00:00
    j = 0
    while j < n:
        submission = input().split()
        current = to_seconds(submission[0])
        result = submission[1]
        if result == "AC":
            difference = current - lastAwake    # how many seconds it has been since last awake
            if difference > timeToFall:     # if more than needed to fall asleep
                longestAsleep = max(longestAsleep, difference - timeToFall)     # update if more than current longest
            lastAwake = current
        j += 1
    tillEnd = 14 * 3600 - lastAwake     # how many seconds until the contest ends (14:00:00)
    if tillEnd > timeToFall:    # end of contest wakes them up
        longestAsleep = max(longestAsleep, tillEnd - timeToFall)
    print_result(longestAsleep)
    i += 1
