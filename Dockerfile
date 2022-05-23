FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install -y cmake g++ libboost-all-dev libssl-dev libcurl4-openssl-dev \
    && apt-get install -y curl vim wget git \
    && rm -rf /var/lib/apt/lists/* 

# Taemin's utils..
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.1/zsh-in-docker.sh)"

WORKDIR /usr/src
