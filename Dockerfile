FROM ubuntu:22.04

# set working directory
WORKDIR /app

COPY packages.txt requirements.txt /tmp

# set timezone
RUN ln -snf /usr/share/zoneinfo/$CONTAINER_TIMEZONE /etc/localtime && \
    echo $CONTAINER_TIMEZONE > /etc/timezone

# update package information and install required packages
RUN apt-get update && \
    xargs -a /tmp/packages.txt apt-get install -y && \
    pip install --no-cache-dir -r /tmp/requirements.txt && \
    apt-get autoremove -y && \
    apt-get clean

# clean up stale packages
RUN apt-get clean -y && \
    apt-get autoremove --purge -y && \
    rm -rf /var/lib/apt/lists/*
