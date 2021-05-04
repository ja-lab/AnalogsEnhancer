**Building**

Install vitasdk https://vitasdk.org

Brief Instructions:

Install required prequisites:
```
brew install wget cmake
export VITASDK=~/Documents/code/vitasdk
export PATH=$VITASDK/bin:$PATH # add vitasdk tool to $PATH
git clone https://github.com/vitasdk/vdpm
cd vdpm
./bootstrap-vitasdk.sh
./install-all.sh
```

To Build:
```
export VITASDK=~/Documents/code/vitasdk
export PATH=$VITASDK/bin:$PATH # add vitasdk tool to $PATH
cmake .
make
```
