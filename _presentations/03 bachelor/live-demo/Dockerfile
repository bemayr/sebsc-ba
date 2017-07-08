FROM ubuntu:16.10
MAINTAINER Bernhard Mayr <bernhard@mayr.io>

# install gcc, g++ and valgrind
RUN apt-get update && \
    apt-get install -y build-essential valgrind

# change working directory
WORKDIR /app

# automatically run bash
CMD /bin/bash
