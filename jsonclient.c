/*
17.11.2015
Minttu Hämäläinen
e1201352

To compile it, run:

$ gcc -o jsonclient jsonclient.c
$ ./jsonclient 
USAGE: jsonclient host [page]
	host: the website hostname. ex: coding.debuntu.org
	page: the page to retrieve. ex: index.html, default: /

Informative messages and errors are printed to stderr. The content of the page is printed to stdout. Thus, to save the HTML content of a page to a file, you will need to run:

$ ./htmlget coding.debuntu.org category > /tmp/page.html

*/  

  #include <stdio.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <stdlib.h>
    #include <netdb.h>
    #include <string.h>
	#include "json.h"
	
    int create_tcp_socket();				
    char *get_ip(char *host);
    char *build_get_query(char *host, char *page);
    void usage();
     
    #define HOST "www.cc..puv.fi"
    #define PAGE "/~e1201352/"
    #define PORT 80							//defined port 80 http
    #define USERAGENT "HTMLGET 1.0"			//whaaat?
     
    int main(int argc, char **argv)
    {
	 // for json {contenttype : application/javascript}
      struct sockaddr_in *remote;
      int sock;
      int tmpres;
      char *ip;
      char *get;
      char buf[BUFSIZ+1];
      char *host;
      char *page;
     
      if(argc == 1){
        usage();
        exit(2);
      }  
      host = argv[1];
      if(argc > 2){
        page = argv[2];
      }else{
        page = PAGE;
      }
      sock = create_tcp_socket();
      ip = get_ip(host);
      fprintf(stderr, "IP is %s\n", ip);
      remote = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
      remote->sin_family = AF_INET;
      tmpres = inet_pton(AF_INET, ip, (void *)(&(remote->sin_addr.s_addr)));
      if( tmpres < 0)  
      {
        perror("Can't set remote->sin_addr.s_addr");
        exit(1);
      }else if(tmpres == 0)
      {
        fprintf(stderr, "%s is not a valid IP address\n", ip);
        exit(1);
      }
      remote->sin_port = htons(PORT);
     
      if(connect(sock, (struct sockaddr *)remote, sizeof(struct sockaddr)) < 0){
        perror("Could not connect");
        exit(1);
      }
      get = build_get_query(host, page);
      fprintf(stderr, "Query is:\n<<START>>\n%s<<END>>\n", get); // writing into stderr "Query is host, page from build get query(..)
     
	 
      //Send the query to the server
      int sent = 0;
      while(sent < strlen(get))
      {
        tmpres = send(sock, get+sent, strlen(get)-sent, 0);
        if(tmpres == -1){
          perror("Can't send query");
          exit(1);
        }
        sent += tmpres;
      }
      //now it is time to receive the page
      memset(buf, 0, sizeof(buf));
      int htmlstart = 0;
      char * htmlcontent;
      while((tmpres = recv(sock, buf, BUFSIZ, 0)) > 0){										//as long as theres data
        if(htmlstart == 0) 																	//first time in here, lets check theres anything to read and save
        {
          /* Under certain conditions this will not work.
          * If the \r\n\r\n part is splitted into two messages
          * it will fail to detect the beginning of HTML content
          */
          htmlcontent = strstr(buf, "\r\n\r\n"); 											//pointer to "\r\n\r\n" (end of http header)
          if(htmlcontent != NULL){ 															//if not 0 there's something to recive
            htmlstart = 1; 																	//start point to 1 (from 0, not to enter here again)
            htmlcontent += 4; 																//start readin?receving http content (comes after the haeder ending)
          }
        }else{
          htmlcontent = buf;																//if htmlstart is not zero (should be zero only the first time) write to buffer
        }
        if(htmlstart){																		//after fist time in here, lets save data there is
          fprintf(stdout, htmlcontent);														//Thus, to save the HTML content of a page to a file, you will need to run: 
        }																					//$ ./htmlget coding.debuntu.org category > /tmp/page.html
     
        memset(buf, 0, tmpres);																//writin 0 to buffer as long as the recv is
      }
      if(tmpres < 0)
      {
        perror("Error receiving data");
      }
      free(get);
      free(remote);
      free(ip);
      close(sock);
      return 0;
    }
     
    void usage()
    {
      fprintf(stderr, "USAGE: jsonclient host [page]\n\
    \thost: the website hostname. ex: coding.debuntu.org\n\
    \tpage: the page to retrieve. ex: index.html, default: /\n");
    }
     
     
    int create_tcp_socket()
    {
      int sock;
      if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        perror("Can't create TCP socket");
        exit(1);
      }
      return sock;
    }
     
     
    char *get_ip(char *host)
    {
      struct hostent *hent;
      int iplen = 15; 																			//XXX.XXX.XXX.XXX
      char *ip = (char *)malloc(iplen+1);
      memset(ip, 0, iplen+1);
      if((hent = gethostbyname(host)) == NULL)
      {
        herror("Can't get IP");
        exit(1);
      }
      if(inet_ntop(AF_INET, (void *)hent->h_addr_list[0], ip, iplen) == NULL)
      {
        perror("Can't resolve host");
        exit(1);
      }
      return ip;
    }
     
    char *build_get_query(char *host, char *page)
    {
      char *query;
      char *getpage = page;
      char *tpl = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n"; 
      if(getpage[0] == '/'){
        getpage = getpage + 1;
        fprintf(stderr,"Removing leading \"/\", converting %s to %s\n", page, getpage);
      }
      // -5 is to consider the %s %s %s in tpl and the ending \0
      query = (char *)malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
      sprintf(query, tpl, getpage, host, USERAGENT);
      return query;
    }