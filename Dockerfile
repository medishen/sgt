FROM ubuntu:22.04
RUN apt-get update && apt-get install -y make gcc
WORKDIR /usr/src/app
COPY . /usr/src/app
RUN make -f Makefile install
RUN chmod +x /usr/local/bin/sgt
ENTRYPOINT ["/usr/local/bin/sgt"]
CMD []