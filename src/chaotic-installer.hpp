#ifndef CHAOTIC_INSTALLER_H
#define CHAOTIC_INSTALLER_H

#define QML_PATH "qml/"
#define ASSETS_PATH "assets/"

void set_keys();
void update_mirrors();
void check_connection();
void set_locale();
void set_zone();
void prepare_drives();
void install_options();
void set_hostname();
void set_user();
void add_software();
void install_base();
void configure_system();
void add_user();
void reboot_system();

#endif // CHAOTIC_INSTALLER_H