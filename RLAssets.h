#ifndef RLASSETS_H
#define RLASSETS_H

/// <summary>
/// Gets the application (exe) directory for the currently running program
/// </summary>
/// <returns>The path on disk in the current OSs format</returns>
const char* rlas_GetApplicationBasePath();

/// <summary>
/// adds a subpath (folder or file) to the specified path with the correct characters for the current OS
/// </summary>
/// <param name="path">the root path</param>
/// <param name="subpath">the sub path to append</param>
/// <param name="destination">the destination string</param>
/// <param name="lenght">the lenght of the destination string</param>
/// <returns>the lenght of the resulting combined path, -1 if the destination was not long enough</returns>
int rlas_AppendPath(const char* path, const char* subpath, char* destination, int lenght);

/// <summary>
/// Sets the initial asset path on disk
/// </summary>
/// <param name="path">The path to use as the asset root</param>
/// <param name="relativeToApp">When true the specified path will be used relative to the application root and should be in unix (/) format, when false the path specified is in the OSs format</param>
void rlas_SetAssetRootPath(const char* path, bool relativeToApp);

/// <summary>
/// Returns the top level asset root path
/// </summary>
/// <returns>The path on dis (OS format) of the inital asset root</returns>
const char* rlas_GetAssetRootPath();

/// <summary>
/// Adds an additional asset path to the search path for assets
/// The the specified path will be treated as '/' for relative paths
/// Any files that are duplicated in resource paths will be 'merged' into the virtual file structure and override older paths
/// </summary>
/// <param name="path">The resource path root to add</param>
void rlas_AddAssetResourcePath(const char* path);

/// <summary>
/// Gets the path on disk for an assets relative path
/// If multiple resource paths exist with the asset, the one added last will be returned.
/// </summary>
/// <param name="path">The relative path of the asset to look up</param>
/// <returns>The path on disk of the asset</returns>
const char* rlas_GetAssetPath(const char* path);

/// <summary>
/// Returns a list of all relative asset names in a resource path
/// Call once with results as NULL to get the count to allocate a result buffer large enough
/// Then call again with buffer to get results.
/// </summary>
/// <param name="path">The relative path to search </param>
/// <param name="includeSubDirectories">Search into subdirectories</param>
/// <param name="results">A pointer to a character array to store the results, when null not used.</param>
/// <returns>The number of asset items found</returns>
int rlas_GetAssetsInPath(const char* path, bool includeSubDirectories, char** results);

#endif //RLASSETS_H

