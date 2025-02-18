#!/bin/sh
docker run --rm -it --ipc=host shared_memory_app /bin/bash -c "./writer | ./reader"
