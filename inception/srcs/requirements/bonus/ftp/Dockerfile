FROM debian:10

RUN	apt-get update -y && apt-get install vsftpd -y

COPY conf/vsftpd.conf /etc/vsftpd/vsftpd.conf

COPY tools/configure.sh /tmp/configure.sh

EXPOSE 21/tcp

ENTRYPOINT ["sh", "/tmp/configure.sh"]