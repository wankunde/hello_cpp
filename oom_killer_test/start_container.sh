#!/bin/bash
set -x
CONTAINER_NAME=mem_alloc
docker stop ${CONTAINER_NAME}
docker rm ${CONTAINER_NAME}
docker run -d --name ${CONTAINER_NAME} ${CONTAINER_NAME}:v1

sleep 2
CONTAINER_ID=$(docker ps --format "{{.ID}}\t{{.Names}}" | grep -i ${CONTAINER_NAME} | awk '{print $1}')
echo "Docker container id: ${CONTAINER_ID}"

CGROUP_CONTAINER_PATH=$(find /sys/fs/cgroup/memory/ -name "*${CONTAINER_ID}*")
echo ""${CGROUP_CONTAINER_PATH}

echo 536870912 > ${CGROUP_CONTAINER_PATH}/memory.limit_in_bytes
usage_in_bytes=$(cat ${CGROUP_CONTAINER_PATH}/memory.usage_in_bytes)
limit_in_bytes=$(cat ${CGROUP_CONTAINER_PATH}/memory.limit_in_bytes)
echo "usage_in_bytes: ${usage_in_bytes}, limit_in_bytes: ${limit_in_bytes}"
