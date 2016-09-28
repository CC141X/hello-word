/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * Author:  Administrator
 * Created: 2016-9-28
 */

create database bookmarks;
use bookmarks;

create table user(
    username varchar(16) not null primary key,
    password char(40) not null,
    email varchar(100) not null
);

create table bookmark(
    username varchar(16) not null,
    bm_URL varchar(255) not null,
    index (username),
    index (bm_URL)，
    primary key(username,bm_URL)
);

grant select, insert, update, delete
on bookmarks.*
to bm_user@localhost identified by 'password';