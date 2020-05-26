-- # 创建日期表
create table if not exists date_info (
    date_id int primary key auto_increment not null,
    date_str varchar(10) not null
);

insert into date_info values(1, "周一"),(2, "周二"),(3, "周三"),(4, "周四"),(5, "周五");

-- # 创建时间表
create table if not exists time_info(
    time_id int primary key auto_increment not null,
    time_str varchar(10) not null 
);

insert into time_info values(1, "上午"), (2, "下午");

-- # 创建机房信息表
create table if not exists room_info(
    room_id int primary key auto_increment not null,
    room_name varchar(10) not null,
    room_max_num int not null
);

insert into room_info values(1, "1号机房", 20),
                            (2, "2号机房", 50),
                            (3, "3号机房", 100);

-- # 创建用户信息表
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

-- # 创建预约信息表
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

-- # 修改一下room_info表格，增加一个字段，座位余量字段
alter table room_info add room_margin int not null;
update room_info set room_margin = 20 where room_id = 1;
update room_info set room_margin = 50 where room_id = 2;
update room_info set room_margin = 100 where room_id = 3;

-- # 修改预约表,添加一览状态栏
alter table order_info add state_id int not null;

-- # 新建一个预约状态表
create table if not exists state_info (
    state_id int primary key auto_increment not null,
    state_str varchar(10) not null
);

insert into state_info values(1, "待审核"),(2,"通过")(3,"不通过");

-- # 给预约表添加外健
alter table order_info add foreign key (state_id) references state_info(state_id) on delete cascade on update cascade;

-- 机房余量需要区分上午和下午，所以修改一下机房表
alter table room_info change room_margin room_margin_am int not null;
alter table room_info add room_margin_pm int not null;
update room_info set room_margin_pm = 20 where room_id = 1;
update room_info set room_margin_pm = 50 where room_id = 2;
update room_info set room_margin_pm = 100 where room_id = 3;

-- 房间余量数据表还得更改，余量需要单独放置在记账表格中
-- 删除原先的余量列
alter table room_info drop room_margin_am;
alter table room_info drop room_margin_pm;
-- 周一
create table if not exists monday_room_margin(
    room_id int not null,
    room_margin_am int not null,
    room_margin_pm int not null,
    foreign key(room_id) references room_info(room_id) on delete cascade on update cascade
);
insert into monday_room_margin values(1, 20, 20);
insert into monday_room_margin values(2, 50, 50);
insert into monday_room_margin values(3, 100, 100);
-- 周二
create table if not exists tuesday_room_margin(
    room_id int not null,
    room_margin_am int not null,
    room_margin_pm int not null,
    foreign key(room_id) references room_info(room_id) on delete cascade on update cascade
);
insert into tuesday_room_margin values(1, 20, 20);
insert into tuesday_room_margin values(2, 50, 50);
insert into tuesday_room_margin values(3, 100, 100);
-- 周三
create table if not exists wednesday_room_margin(
    room_id int not null,
    room_margin_am int not null,
    room_margin_pm int not null,
    foreign key(room_id) references room_info(room_id) on delete cascade on update cascade
);
insert into wednesday_room_margin values(1, 20, 20);
insert into wednesday_room_margin values(2, 50, 50);
insert into wednesday_room_margin values(3, 100, 100);
-- 周四
create table if not exists thursday_room_margin(
    room_id int not null,
    room_margin_am int not null,
    room_margin_pm int not null,
    foreign key(room_id) references room_info(room_id) on delete cascade on update cascade
);
insert into thursday_room_margin values(1, 20, 20);
insert into thursday_room_margin values(2, 50, 50);
insert into thursday_room_margin values(3, 100, 100);
-- 周五
create table if not exists friday_room_margin(
    room_id int not null,
    room_margin_am int not null,
    room_margin_pm int not null,
    foreign key(room_id) references room_info(room_id) on delete cascade on update cascade
);
insert into friday_room_margin values(1, 20, 20);
insert into friday_room_margin values(2, 50, 50);
insert into friday_room_margin values(3, 100, 100);

