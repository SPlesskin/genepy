FROM debian:9

# Add the installer to this Docker image
COPY *.deb /tmp

# Install Genepy (with root permissions)
RUN apt-get update && \
    apt-get install -y /tmp/*.deb

# Create a new user and login as that user
ENV user erwan
RUN useradd -ms /bin/bash ${user}
USER ${user}
WORKDIR /home/${user}

#
# NOW GENEPY CAN BE USED WITH A NON-ROOT USER.
#
