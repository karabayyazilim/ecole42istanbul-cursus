FROM alpine:3.15.0

RUN apk update
RUN apk upgrade
RUN rm -rf /var/cache/apk/*

RUN apk add --update --no-cache curl make git

RUN apk add --update --no-cache nodejs npm
RUN npm install -g pnpm


RUN apk add --update --no-cache go
ENV PATH=$PATH:/usr/local/go/bin:/root/go/bin
RUN go version

RUN go install github.com/cespare/reflex@latest

COPY ./conf/script.sh /script.sh
RUN chmod +x script.sh

COPY ./conf/package.json /package.json

CMD ["sh", "script.sh"]