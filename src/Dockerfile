FROM gcc:11.3.0

WORKDIR /app

COPY writer.c reader.c build.sh run.sh ./

RUN gcc -o writer writer.c  && \
    gcc -o reader reader.c
RUN chmod +x build.sh run.sh

CMD ["/bin/bash", "-c", "./writer | ./reader"]
