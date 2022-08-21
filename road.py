from bs4 import BeautifulSoup
from urllib.request import urlopen
import math

def dist(coord1, coord2):
    dlat = abs(coord1[0] - coord2[0])
    dlon = abs(coord1[1] - coord2[1])
    d = math.sqrt((dlat * 111.11) ** 2 + (dlon * 111.11 * math.sin(coord1[0]) / 180 * math.pi) ** 2)
    return d
minlat = 60.9651
minlon = 68.9868
maxlat = 61.0198
maxlon = 69.0759
s = 0
dlat = (maxlat - minlat) / 5
dlon = (maxlon - minlon) / 5
dct = {}
for i in range(5):
    for j in range(5):
        nminlat = minlat + i * dlat
        nmaxlat = nminlat + dlat
        nminlon = minlon + j * dlon
        nmaxlon = nminlon + dlon
        url = urlopen('https://www.openstreetmap.org/api/0.6/map?bbox='+ str(nminlon) +'%2C'+ str(nminlat) +'%2C'+ str(nmaxlon) +'%2C' + str(nmaxlat))
        xml = BeautifulSoup(url, 'lxml')
        for node in xml.find_all('node'):
            dct[int(node['id'])] = (float(node['lat']), float(node['lon']))
        for way in xml.find_all('way'):
            flag = False
            for tag in way('tag'):
                if tag['k'] == 'highway':
                    flag = True
            if flag:
                roadnodes = []
                for nd in way('nd'):
                    ref = int(nd['ref'])
                    roadnodes.append(ref)
                for p in range(len(roadnodes)-1):
                    coord1 = dct[roadnodes[p]]
                    coord2 = dct[roadnodes[p+1]]
                    s += dist(coord1, coord2)
print(s)
