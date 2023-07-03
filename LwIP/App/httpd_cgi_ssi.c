/**
  ******************************************************************************
  * @file    USB_Device/CDC_RNDIS_Server/USB_Device/App/httpd_cg_ssi.c
  * @author  MCD Application Team
  * @brief   Webserver SSI and CGI handlers
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lwip/debug.h"
#include "lwip/tcp.h"
#include "lwip/apps/httpd.h"
#include "http_cgi_ssi.h"
#include <string.h>
#include <stdlib.h>


/* Array of tags for the SSI handler */
#define numSSItags 1
char const *theSSItags[numSSItags] = {"tag1"};

void myCGIinit(void);
u16_t mySSIHandler(int iIndex, char *pcInsert, int iInsertLen);
void mySSIinit(void);

/* CGI handler for LED control */

/* Html request for "/leds.cgi" will start LEDS_CGI_Handler */

/* Cgi call table, only one CGI used */
tCGI CGI_TAB[1];

/* Initialize the CGI handlers */
void myCGIinit(void)
{
  /* Add LED control CGI to the table */

  /* Give the table to the HTTP server */
  http_set_cgi_handlers(CGI_TAB, 1);
} /* myCGIinit */

/**
  * @brief  CGI handler for LEDs control
  */
/**** SSI handler ****/
void http_server_init(void)
{
  /* Httpd Init */
  httpd_init();

  /* configure CGI handlers (LEDs control CGI) */
  myCGIinit();

    /* configure SSI handlers */
  mySSIinit();
}

