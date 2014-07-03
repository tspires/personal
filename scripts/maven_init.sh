#!/bin/bash
mvn archetype:generate -DgroupId=com.tspires.$1 -DartifactId=$1 -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
