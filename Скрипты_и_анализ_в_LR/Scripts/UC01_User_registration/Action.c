Action()
{ int randomNumber;
 char *one,*two,*three,*four,*five;
 	one = lr_eval_string("{randomChar}");
 	two = lr_eval_string("{randomChar}");
 	three = lr_eval_string("{randomChar}");
 	four = lr_eval_string("{randomChar}");
 	five = lr_eval_string("{randomChar}");
		
 	lr_param_sprintf("user","%s%s%s%s%s",one,two,three,four,five);

	web_set_max_html_param_len("2000000");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Priority", 
		"u=1");

	web_add_auto_header("DNT", 
		"1");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("dev-boomq.pflb.ru", 
		"URL=https://dev-boomq.pflb.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		LAST);

	web_websocket_send("ID=1", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1718621832087\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 1 received buffer WebSocketReceive0*/

	lr_start_transaction("UC_01_TR_01_Sign_in");

	web_revert_auto_header("Priority");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2024-06-17T13:56:57.549Z");
	
	web_reg_save_param_ex(
		"ParamName=token",
		"LB=",
		"RB=\n",
		SEARCH_FILTERS,
		"Scope=HEADERS",
		"HeaderNames=Authorization",
		LAST);

	
	
	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={user_11}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_auto_header("Authorization",
		"Bearer {token}");

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
    web_reg_save_param_json(
		"ParamName=teamId",
		"QueryString=$..id",
		SEARCH_FILTERS,
		LAST);
	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	web_reg_save_param_ex(
		"ParamName=boomq_token",
		"LB=boomq_auth=",
		"RB=\n",
		SEARCH_FILTERS,
		"Scope=HEADERS",
		"HeaderNames=set-Cookie",
		LAST);
	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Authorization",
		"Bearer {boomq_token} ");
	
	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_01_Sign_in",LR_AUTO);

	lr_start_transaction("UC_01_TR_02_Going_to_group");
	
	web_add_auto_header("Priority", 
		"u=1");

	lr_think_time(rand()%10 + 10);

	web_url("team_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?page=0&size=4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_02_Going_to_group",LR_AUTO);

	lr_think_time(rand()%5 + 10);

	lr_start_transaction("UC_01_TR_03_Edit_group");

	web_url("13_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/{teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/{teamId}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Priority");
	
	web_add_auto_header("Content-Type",
		"application/json");
	web_url("teamMember", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=13&page=0&size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/{teamId}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_03_Edit_group",LR_AUTO);

	lr_start_transaction("UC_01_TR_05_Add_member");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_header("Priority", 
		"u=1");
	
	randomNumber = rand()%100000 + 1;
	
	lr_save_int(randomNumber, "rand_number");
	
	web_add_auto_header("Content-type", 
		"application/json");

	web_reg_save_param_ex(
		"ParamName=invite_url",
		"LB=\"inviteUrl\":\"",
		"RB=\"",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_json(
		"ParamName=userId",
		"QueryString=$..userId",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_save_param_json(
		"ParamName=id",
		"QueryString=$..id",
		SEARCH_FILTERS,
		LAST);

	web_custom_request("teamMember_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/{teamId}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"email\":\"{user}{rand_number}{email}\",\"permissionList\":[\"ADMIN\",\"VIEW\",\"EDIT\",\"RUN\",\"MANAGE_USERS_IN_ORG\"],\"userDisplayName\":\"{user}_{rand_number}\"}]", 
		LAST);

	web_url("teamMember_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}&page=0&size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/{teamId}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_05_Add_member",LR_AUTO);

	lr_start_transaction("UC_01_TR_06_Copy_invite_link");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("teamMember_5", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId={teamId}", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/{teamId}", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"Body=[{\"email\":\"{user}{rand_number}{email}\",\"id\":{id},\"permissionList\":[\"RUN\",\"ADMIN\",\"MANAGE_USERS_IN_ORG\",\"EDIT\",\"VIEW\"],\"teamId\":\"{teamId}\",\"userDisplayName\":\"{user}_{rand_number}\",\"userId\":{userId},\"updateInviteExpiration\":true}]", 
		LAST);

	lr_end_transaction("UC_01_TR_06_Copy_invite_link",LR_AUTO);

	lr_start_transaction("UC_01_TR_07_Exit");
	
	lr_think_time(5);
	
	lr_end_transaction("UC_01_TR_07_Exit",LR_AUTO);

	lr_start_transaction("UC_01_TR_08_Insert_invite_link");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_save_param_ex(
		"ParamName=new_token",
		"LB=boomq_auth=",
		"RB=; Path=\/",
		SEARCH_FILTERS,
		"Scope=HEADERS",
		"HeaderNames=set-Cookie",
		LAST);
	
	web_url("YJ4JGWAnMH-JhZ5GT-gOPcA-PRx4ftfaASf1R4gfo7ZFXezGvuoTqwD-jwmhTKUgJF7kBCgPDXbUp7yL-StP1Z8fVLcrYDK7n5UDsEqNMTk=", 
		"URL=https://dev-boomq.pflb.ru{invite_url}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_08_Insert_invite_link",LR_AUTO);

	lr_start_transaction("UC_01_TR_09_Input_password");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("modelSchema_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/change-password", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Authorization",
		"Bearer {new_token}");
	
	web_custom_request("user_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/change-password", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"Body={\"password\":\"{password_new_user}\"}", 
		LAST);

	web_revert_auto_header("Priority");

	web_url("team_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner_2", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_01_TR_09_Input_password",LR_AUTO);

	lr_start_transaction("UC_01_TR_10_Exit");
	
	lr_think_time(rand()%5 + 5);
	
	lr_end_transaction("UC_01_TR_10_Exit",LR_AUTO);

	return 0;
}