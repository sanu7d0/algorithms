FROM ubuntu_base11

WORKDIR /usr/src/workspace

# * ubuntu_base11 receipe
# RUN apt update && apt install -y \
#     software-properties-common \
#     curl
# RUN add-apt-repository ppa:ubuntu-toolchain-r/test

RUN apt update && apt install -y \
    gcc-11 \
    g++-11 \
    gdb \
    rustc \
    cargo \
    git
RUN apt update && apt upgrade
# RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# * gdb 11.1 if needed
# https://gist.github.com/richyliu/e9ec03f455bee86dc407b7e051245c0e

LABEL Name=algorithms Version=0.0.1
