import numpy as np
import matplotlib.pyplot as plt

from imageio import imread
from os import listdir
from os.path import isfile, join
import re


# fig = plt.figure()
# ax1 = fig.add_subplot(121)
# ax1.imshow(img)
# ax1.axis('off')
# plt.show()

def get_files(path):
  file_lst = []
  for file in listdir(path):
    if isfile(join(path, file)):
      file_lst.append((get_spp(file), join(path, file)))

  file_lst = sorted(file_lst)
  return [f[1] for f in file_lst]

def get_spp(file):
  return int(file.replace('.', '_').split('_')[-3][:-3])


ref = imread('gt_3600spp.png')
N = ref.shape[0] * ref.shape[1]
spp = []
rms_error = []
spp_rms = {}
for file in get_files('aaf_vary_spp'):
  print(file)
  img = imread(file)
  rms_error.append(np.sqrt(np.sum(np.square(img - ref)) / N))
  spp.append(int(get_spp(file)))
  spp_rms[spp[-1]] = rms_error[-1]

# for key in sorted(spp_rms.keys()):
#   print(key, spp_rms[key])

plt.plot(spp, rms_error)
plt.xlabel('Avg spp')
plt.ylabel('RMS error')
plt.show()
