#!/bin/bash

# This script generates a list of all contributors to the repository.

# Get a list of authors and their emails
git log --format='%aN <%aE>' | sort -u > AUTHORS

# Add header to the file
echo -e "# File @generated by simple_shell/generate-authors.sh. DO NOT EDIT.\n# This file lists all contributors to the repository.\n# See simple_shell/generate-authors.sh to make modifications.\n$(cat AUTHORS)" > AUTHORS

