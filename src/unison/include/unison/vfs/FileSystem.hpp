//          Copyright Timothy Goya 2007.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef UNISON_VFS_FILE_SYSTEM_HPP
#define UNISON_VFS_FILE_SYSTEM_HPP

#include <string>
#include <vector>

namespace Unison
{
   namespace VFS
   {
      class FileSystem
      {
         public:
            static FileSystem &get()
            {
               static FileSystem vfs;
               return vfs;
            }

            void follow_sym_links(bool follow);
            void normalize_paths(bool normalize);
            bool does_normalization() const;

            static std::string dirname(const std::string &filename);
            static std::string basename(const std::string &filename);
            static std::string strip_ext(const std::string &filename);
            static std::string get_ext(const std::string &filename);
            static std::string normalize(const std::string &path);

            std::string get_dir_sep() const;
            std::string get_base_dir() const;
            std::string get_user_dir() const;

            std::string get_write_dir() const;
            void set_write_dir(const std::string &write_dir);

            void mount(const std::string &path, const std::string &mount_point = "/", bool append = false);
            void umount(const std::string &path);
            std::vector<std::string> get_search_path() const;
            std::string get_mount_point(const std::string &path) const;

            void mkdir(const std::string &dir);
            void rm(const std::string &filename);
            std::vector<std::string> ls(const std::string &path) const;
            bool exists(const std::string &filename) const;
            bool is_dir(const std::string &filename) const;

            std::string get_real_dir(const std::string &filename) const;
         private:
            FileSystem();
            ~FileSystem();

            bool do_normalize;
      };
   }
}

#endif