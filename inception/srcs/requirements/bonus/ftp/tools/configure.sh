#!/bin/sh

if [ ! -f "/etc/vsftpd/vsftpd.conf.bak" ]; then

    cp /etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf.bak

    adduser --disabled-password --gecos "" $FTP_USER
    echo "$FTP_USER:$FTP_PASSWORD" | /usr/sbin/chpasswd &> /dev/null
    chown -R $FTP_USER:$FTP_USER /var/www/html

    echo $FTP_USER | tee -a /etc/vsftpd.userlist &> /dev/null
fi

echo "FTP started on :21"
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
