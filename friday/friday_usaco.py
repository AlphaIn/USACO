#Sean Gao has supplied this straightforward Python solution:

def is_leap_year(year):
    ret = False
    if year % 100 == 0:
        ret = year % 400 == 0
    else:
        ret = year % 4 == 0
    return ret

with open ('friday.in', 'r') as fin:
    raw_line = fin.readline()
years = int(raw_line.strip())

weekdays = [0] * 7
days_of_months = [31,28,31,30,31,30,31,31,30,31,30,31]

curr_days = 0
for year in range(1900, 1900+years):
    for month in range(12):
        _13th = 13 + curr_days
        weekday = _13th % 7
        mon = month+1
        weekdays[weekday] += 1
        curr_days += days_of_months[month]
        if month == 1 and is_leap_year(year):
            curr_days += 1
output = str(weekdays[6])	# task wants specific order
for n in range(6):
    output += ' ' + str(weekdays[n])
with open ('friday.out', 'w') as fout:
    fout.write(output + '\n')