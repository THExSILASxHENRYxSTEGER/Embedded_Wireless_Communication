FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    make \
    gcc-arm-none-eabi \
    && rm -rf /var/lib/apt/lists/*

# Development

WORKDIR /app

# Production (Uncomment the line blow and comment out the line above)
# RUN make
