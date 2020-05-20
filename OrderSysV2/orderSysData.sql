# 创建日期表
eate table if not exists date_info (
    date_id int primary key auto_increment not null,
    date_str varchar(10) not null
);

insert into date_info values(1, "周一"),(2, "周二"),(3, "周三"),(4, "周四"),(5, "周五");

# 创建时间表
create table if not exists time_info(
    time_id int primary key auto_increment not null,
    time_str varchar(10) not null 
);

insert into time_info values(1, "上午"), (2, "下午");

# 创建机房信息表
create table if not exists room_info(
    room_id int primary key auto_increment not null,
    room_name varchar(10) not null,
    room_max_num int not null
);

insert into room_info values(1, "1号机房", 20),
                            (2, "2号机房", 50),
                            (3, "3号机房", 100);

# 创建用户信息表
create table if not exists user_info(
    user_id varchar(10) primary key not null,
    name varchar(32) not null,
    pwd varchar(32) not null,
    identity enum('admin','student','teacher') not null
);

insert into user_info values("1", "Tom", "e10adc3949ba59abbe56e057f20f883e", "admin"),
                            ("101", "Jack", "e10adc3949ba59abbe56e057f20f883e", "teacher"),
                            ("131141143", "Fred", "e10adc3949ba59abbe56e057f20f883e", "student"),
                            ("131141101", "Lily", "e10adc3949ba59abbe56e057f20f883e", "student");

# 创建预约信息表
create table if not exists order_info(
    order_id int primary key auto_increment not null,
    user_id varchar(10) not null,
    order_date int not null,
    order_time int not null,
    order_room int not null,
    foreign key(user_id) references user_info(user_id) on delete cascade on update cascade,
    foreign key(order_date) references date_info(date_id) on delete cascade on update cascade,
    foreign key(order_time) references time_info(time_id) on delete cascade on update cascade,
    foreign key(order_room) references room_info(room_id) on delete cascade on update cascade
);