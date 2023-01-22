FROM ubuntu:latest

RUN apt update && apt install -y \
        make \
        pandoc \
        curl \
        python3.10-venv 


RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        texlive-xetex \
        lmodern \
        texlive
		
