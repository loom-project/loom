#!/bin/sh

./testrunner -f text -f junit

# rename files
DATE=`date +"%Y%m%d%H%M%S"`
for f in `ls reports/TEST-*.xml`
do
    NAME=`basename ${f} | cut -d- -f2-`
    mv ${f} reports/${DATE}-${NAME}
done
