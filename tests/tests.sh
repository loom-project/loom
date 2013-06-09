#!/bin/sh
# Runs the testrunner for loom and timestamps generated reports.
# Copyright (C) 2013 Commonwealth of Australia
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

./testrunner -f text -f junit

# rename files
DATE=`date +"%Y%m%d%H%M%S"`
for f in `ls reports/TEST-*.xml`
do
    NAME=`basename ${f} | cut -d- -f2-`
    mv ${f} reports/${DATE}-${NAME}
done
